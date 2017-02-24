# install.packages('ggplot2')
library(ggplot2)

library(plyr)
library(stringr)

n = 541

df <- data.frame(experiment = numeric(n+1), ReplicationTime  = numeric(n+1))

#import files

for(exp in 0:n){
  
  #pathElems <- c("/home/lacl/work_ndn/dump-trace-", ".txt")
  pathElems <- c("/home/lacl/Dropbox/simulation/dump-trace-", ".txt")
  
  
  file <- paste(pathElems, collapse=toString(exp))
  
  if (file.exists(file)){ #check file existence 
    data = read.table(file, header=F, sep=";")
    
    
    
    
    
    
    # Y1 Replication time
    
    
    storLine <- grep("storage", data$V3) #store storages
    
    stopLine <- grep("stop", data$V3) #store stop
    
    part1 <- data[storLine,]
    part2 <- data[stopLine,]
    
    global <- rbind(part1,part2)
    
    #results <- cbind(part,str_split_fixed(part$V3, "/", Inf))
    
    
    #res <- c("Time","ID","Value") # will generate a warning due to NA when looping
    res <- data.frame(character(),character(),character())
    for(i in 1:nrow(global)){
      
      #keep only rows corresponding to start and stop replication command from an admin node lacl-AdminID
      if(length(grep(paste0("lacl",global[i,2]),global[i,3])) == 1){
        res <- rbind(res, global[i,])
        #res <- rbind(res, dump.trace.1[grep(paste0("lacl",i),part[i,3]),])
      }
      
    }
    
    #res <- res[-1,] #remove the first row wich contains the NA
    
    X <- split(res$V1, res$V2) #keep only the min and max time which represent the start and completion time
    
    val <- data.frame(repTime = numeric(length(X))) #value for the replication Time for every request in the experiment
    for(i in 1:length(X)){
      
      #maxi = as.numeric(max(X[[i]]))
      #mini = as.numeric(min(X[[i]]))
      #dif = maxi-mini
      # print(dif)
      val$repTime[i] <- as.numeric(max(X[[i]])) - as.numeric(min(X[[i]]))
    }
    
    moy = mean(val$repTime)
    
    
    
    df$experiment[exp+1] = exp
    df$ReplicationTime[exp+1] = moy
    
  }# end if
  
} #end for
df

#####################

ggplot(data=df, aes(x=experiment, y=ReplicationTime, group=1)) +
  geom_line() +
  geom_point()