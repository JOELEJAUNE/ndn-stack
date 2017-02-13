
# Set the working directory
setwd("~/Documents/NDFS/Data")


#Generate a data frame from all combinations of factors
data = expand.grid(c(0,1),c(0,1),c(0,1),c(0,1),c(0,1),c(0,1),c(0,1),c(0,1),c(0,1),c(0,1),c(0,1),c(0,1),c(0,1),c(0,1),c(0,1))

# Write CSV in R
#write.csv(data, file = "data.csv",row.names=FALSE)

# Write CSV in R
write.table(data, file = "data.csv",row.names=FALSE, na="",col.names=FALSE, sep=",")