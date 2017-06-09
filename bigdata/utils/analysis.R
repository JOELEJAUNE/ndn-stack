# install.packages('ggplot2')
library(ggplot2)

library(plyr)
library(stringr)
library(dplyr)

n = 57

df <- data.frame(experiment = numeric(n+1), ReplicationTime  = 
                   numeric(n+1), nbNodeBeforeRes = numeric(n+1), RetrieveTime = 
                   numeric(n+1), TotalReplication = numeric(n+1) )

#import files

for(exp in 0:n){
  
  pathElems <- c("~/data/dump-trace-", ".txt")
  #pathElems <- c("/home/lacl/Dropbox/simulation/dump-trace-", ".txt")
  
  
  
  file <- paste(pathElems, collapse=toString(exp))
  
  if (file.exists(file) && file.size(file) > 0){ #check file existence
    data = read.table(file, header=T, sep=";")
    
    
    
    
    
    
    # Y1 Replication time
    
    
    storLine <- grep("storage", data$Name) #store storages
    
    stopLine <- grep("stop", data$Name) #store stop
    
    part1 <- data[storLine,]
    part2 <- data[stopLine,]
    
    #global <- rbind(part1,part2)
    
    #results <- cbind(part,str_split_fixed(part$V3, "/", Inf))
    
    
    #res <- c("Time","ID","Value") # will generate a warning due to NA when looping
    res1 <- data.frame(character(),character(),character())
    res2 <- data.frame(character(),character(),character())
    for(i in 1:nrow(part1)){
      
      #keep only rows corresponding to start and stop replication command from an admin node lacl-AdminID
      if(length(grep(paste0("lacl",part1[i,2],"/"),part1[i,4])) == 1){
        res1 <- rbind(res1, part1[i,])
        #res <- rbind(res, dump.trace.1[grep(paste0("lacl",i),part[i,3]),])
      }
      
    }
    
    for(i in 1:nrow(part2)){
      
      #keep only rows corresponding to start and stop replication command from an admin node lacl-AdminID
      if(length(grep(paste0("lacl",part2[i,2],"/"),part2[i,4])) == 1){
        res2 <- rbind(res2, part2[i,])
        #res <- rbind(res, dump.trace.1[grep(paste0("lacl",i),part[i,3]),])
      }
      
    }
    
    #res <- res[-1,] #remove the first row wich contains the NA
    
   
  if(nrow(res2)!=0){ 
    X <- split(res1$Time, res1$Node) #keep only the min and max time which represent the start and completion time
    Y <- split(res2$Time, res2$Node)
    val <- data.frame(repTime = numeric(min(length(X),length(Y)))) #value for the replication Time for every request in the experiment
    for(i in 1:min(length(X),length(Y))){
      
      #maxi = as.numeric(max(X[[i]]))
      #mini = as.numeric(min(X[[i]]))
      #dif = maxi-mini
      # print(dif)
      val$repTime[i] <- as.numeric(min(Y[[i]])) - as.numeric(min(X[[i]]))
      
      moy = mean(val$repTime)
    }
  }else 
    {
      moy = NA
   }
    
    
    
    
    
    df$experiment[exp+1] = exp
    df$ReplicationTime[exp+1] = moy
    
    # Mean distance before an interest reach a Storage
    
    dataInterest <- filter(data, !grepl("Interest", data$Name)) #keep only lines from data request interest
    
    dataInterest <- filter(dataInterest, !grepl("data", dataInterest$Type)) #added 4/21 remove the data lines
    
    data_count <- ddply(dataInterest, c("Name"), summarise,
                        nbNodes=length(Name))
    
    t = mean(as.numeric(data_count$nbNodes))
    
    df$nbNodeBeforeRes[exp+1] = round(t)
    
    #begin mean retrieve
    dat <- filter(data, !grepl("stop", data$Name))
    dat <- filter(dat, !grepl("storage", dat$Name))
    dat <- filter(dat, !grepl("heartbeat", dat$Name))
    
    v <- dat[c(1,3,4)]
    
    re <- data.frame(character(),character(),character())
    re <- rbind(re,v[1,])
    
    
    current <- v[1,2]
    for(i in 1:nrow(v)){
      
      if(v[i,2]!=current){
        
        re <- rbind(re,v[i,])
        current <- v[i,2]
      }
      
    }
    
    cmp <- data.frame(rep=numeric(nrow(re)))
    for(i in 1:nrow(re)){
      if(i %%2 == 0) {
        cmp$rep[i]=NA
        next()
      }
      cmp$rep[i] = re[1+i,1] - re[i,1]
      
    }
    cmp <- cmp[complete.cases(cmp), ]
    
    #end mean retrieve
    
    a = mean(cmp)
    
   
    df$RetrieveTime[exp+1] = a
    #TotalReplication Total number of  replication requests
    part1 = part1[grep("interest",part1$Type),]
    tDt = as.numeric(length(unique(part1$Name)))
    df$TotalReplication[exp+1]  = tDt
    
    
    
  }# end if
  else
  {
    df$experiment[exp+1] = exp
    df$ReplicationTime[exp+1] = NA
    df$nbNodeBeforeRes[exp+1] = NA
    df$RetrieveTime[exp+1] = NA #
    df$TotalReplication[exp+1] = NA
    
  }
    
}


for(exp in 0:n){
  
  #pathElemsRate <- c("/home/lacl/work_ndn/dump-trace-", ".txt")
  pathElemsRate <- c("~/data/rate-trace-", ".txt")
  
  fileRate <- paste(pathElemsRate, collapse=toString(exp))
  
  if (file.exists(fileRate) && file.size(fileRate) > 0){ #check file existence
    dataRate = read.delim(fileRate, header=T, sep="\t")
    
    dataRate$Node = factor(dataRate$Node)
    dataRate$FaceId <- factor(dataRate$FaceId)
    dataRate$Kilobits <- dataRate$Kilobytes * 8
    dataRate$Type = factor(dataRate$Type)
    dataRate$Time = factor(dataRate$Time)
    
    idata = subset(dataRate, Type %in% c("InInterests", "OutInterests", 
                                         "InData", "OutData"))
    idata = subset(idata, FaceDescr %in% c("appFace://"))
    
    df$experiment[exp+1] = exp
    
    df$NbPackets[exp+1] <-  sum(idata$Packets) #number of packets per sec
    
    df$Rate[exp+1] <-  sum(idata$Kilobits) #Kilobits/s
    
    #df$ReplicationFactor[exp+1] <- i
    
    ##############################################################################
    
    Test = subset(dataRate, Type %in% 
                    c("InSatisfiedInterests","OutSatisfiedInterests","InTimedOutInterests","OutTimedOutInterests"))
    Test = subset(Test, FaceDescr %in% c("appFace://"))
    Test = subset(Test,Packets>0)
    
    
    
    out = subset(idata,Packets>0)
    
    #inInterest
    inInterest = subset(out,Type %in% c("InInterests"))
    df$nbInInterest[exp+1] = length(inInterest$Type)
    
    #outInterest
    outInterest = subset(out,Type %in% c("OutInterests"))
    df$nbOutInterest[exp+1] = length(outInterest$Type)
    
    
    #outData
    outData = subset(out,Type %in% c("OutData"))
    df$nbOutData[exp+1] = length(outData$Type)
    
    #inData
    inData = subset(out,Type %in% c("InData"))
    df$nbInData[exp+1] = length(inData$Type)
    
    #inSatisfiedInterests
    inSati = subset(Test,Type %in% c("InSatisfiedInterests"))
    length(inSati$Type)
    
    #outSatisfiedInterests
    outSati = subset(Test,Type %in% c("OutSatisfiedInterests"))
    length(outSati$Type)
    
    #inTimedOutInterests
    inTime = subset(Test,Type %in% c("InTimedOutInterests"))
    length(inTime$Type)
    
    #out TimedOutInterests
    outTime = subset(Test,Type %in% c("OutTimedOutInterests"))
    length(outTime$Type)
    
    
    #################################3
    
  }#end if
  else
  {
    df$experiment[exp+1] = exp
    df$NbPackets[exp+1] = NA
    df$Rate[exp+1] = NA
    df$nbInInterest[exp+1] = NA
    df$nbOutInterest[exp+1] = NA
    df$nbOutData[exp+1] = NA
    df$nbInData[exp+1] = NA
    
  }
  
}# end for

write.csv(x = df,file = "~/result.csv", sep = ";")
