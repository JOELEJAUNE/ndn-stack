./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=3 --cs=10 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=10 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=0" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=3 --cs=10 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=10 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=1" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=3 --cs=10 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=10 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=2" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=3 --cs=10 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=10 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=3" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=3 --cs=10 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=10 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=4" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=3 --cs=10 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=10 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=5" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=3 --cs=10 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=10 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=6" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=3 --cs=10 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=10 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=7" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=5 --cs=10 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=10 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=8" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=5 --cs=10 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=10 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=9" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=5 --cs=10 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=10 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=10" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=5 --cs=10 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=10 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=11" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=5 --cs=10 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=10 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=12" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=5 --cs=10 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=10 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=13" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=5 --cs=10 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=10 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=14" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=5 --cs=10 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=10 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=15" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=3 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=16" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=3 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=1000 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=17" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=3 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=18" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=3 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=1000 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=19" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=3 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=20" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=3 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=1000 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=21" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=3 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=22" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=3 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=1000 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=23" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=5 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=1000 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=24" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=5 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=25" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=5 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=1000 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=26" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=5 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=27" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=5 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=1000 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=28" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=5 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=29" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=5 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=1000 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=30" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=5 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=31" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=3 --cs=10 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=1000 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=32" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=3 --cs=10 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=33" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=3 --cs=10 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=1000 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=34" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=3 --cs=10 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=35" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=3 --cs=10 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=1000 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=36" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=3 --cs=10 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=37" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=3 --cs=10 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=1000 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=38" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=3 --cs=10 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=39" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=5 --cs=10 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=40" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=5 --cs=10 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=1000 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=41" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=5 --cs=10 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=42" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=5 --cs=10 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=1000 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=43" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=5 --cs=10 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=44" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=5 --cs=10 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=1000 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=45" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=5 --cs=10 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=46" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=5 --cs=10 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=1000 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=47" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=3 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=10 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=48" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=3 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=10 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=49" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=3 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=10 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=50" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=3 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=10 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=51" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=3 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=10 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=52" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=3 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=10 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=53" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=3 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=10 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=54" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=3 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=10 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=55" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=5 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=10 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=56" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=5 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=10 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=57" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=5 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=10 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=58" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=5 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=10 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=59" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=5 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=10 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=60" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=5 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=10 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=61" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=5 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=10 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=62" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=5 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=10 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=63" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=3 --cs=10 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=1000 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=64" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=3 --cs=10 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=65" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=3 --cs=10 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=1000 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=66" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=3 --cs=10 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=67" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=3 --cs=10 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=1000 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=68" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=3 --cs=10 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=69" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=3 --cs=10 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=1000 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=70" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=3 --cs=10 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=71" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=5 --cs=10 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=72" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=5 --cs=10 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=1000 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=73" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=5 --cs=10 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=74" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=5 --cs=10 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=1000 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=75" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=5 --cs=10 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=76" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=5 --cs=10 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=1000 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=77" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=5 --cs=10 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=78" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=5 --cs=10 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=1000 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=79" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=3 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=10 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=80" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=3 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=10 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=81" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=3 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=10 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=82" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=3 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=10 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=83" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=3 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=10 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=84" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=3 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=10 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=85" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=3 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=10 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=86" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=3 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=10 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=87" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=5 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=10 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=88" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=5 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=10 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=89" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=5 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=10 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=90" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=5 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=10 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=91" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=5 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=10 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=92" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=5 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=10 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=93" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=5 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=10 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=94" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=5 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=10 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=95" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=3 --cs=10 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=10 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=96" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=3 --cs=10 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=10 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=97" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=3 --cs=10 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=10 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=98" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=3 --cs=10 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=10 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=99" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=3 --cs=10 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=10 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=100" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=3 --cs=10 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=10 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=101" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=3 --cs=10 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=10 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=102" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=3 --cs=10 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=10 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=103" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=5 --cs=10 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=10 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=104" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=5 --cs=10 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=10 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=105" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=5 --cs=10 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=10 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=106" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=5 --cs=10 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=10 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=107" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=5 --cs=10 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=10 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=108" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=5 --cs=10 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=10 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=109" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=5 --cs=10 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=10 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=110" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=5 --cs=10 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=10 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=111" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=3 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=112" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=3 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=1000 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=113" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=3 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=114" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=3 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=1000 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=115" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=3 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=116" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=3 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=1000 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=117" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=3 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=118" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=3 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=1000 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=119" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=5 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=1000 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=120" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=5 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=121" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=5 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=1000 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=122" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=5 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=123" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=5 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=1000 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=124" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=5 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=125" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=5 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=1000 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=126" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=5 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=127" &
sleep 120./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=3 --cs=10 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=10 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=0" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=3 --cs=10 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=10 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=1" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=3 --cs=10 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=10 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=2" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=3 --cs=10 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=10 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=3" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=3 --cs=10 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=10 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=4" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=3 --cs=10 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=10 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=5" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=3 --cs=10 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=10 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=6" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=3 --cs=10 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=10 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=7" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=5 --cs=10 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=10 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=8" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=5 --cs=10 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=10 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=9" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=5 --cs=10 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=10 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=10" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=5 --cs=10 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=10 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=11" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=5 --cs=10 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=10 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=12" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=5 --cs=10 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=10 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=13" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=5 --cs=10 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=10 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=14" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=5 --cs=10 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=10 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=15" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=3 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=16" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=3 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=1000 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=17" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=3 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=18" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=3 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=1000 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=19" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=3 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=20" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=3 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=1000 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=21" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=3 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=22" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=3 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=1000 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=23" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=5 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=1000 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=24" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=5 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=25" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=5 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=1000 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=26" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=5 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=27" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=5 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=1000 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=28" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=5 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=29" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=5 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=1000 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=30" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=5 --cs=1000 --nCapacity=2 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=31" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=3 --cs=10 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=1000 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=32" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=3 --cs=10 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=33" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=3 --cs=10 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=1000 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=34" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=3 --cs=10 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=35" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=3 --cs=10 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=1000 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=36" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=3 --cs=10 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=37" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=3 --cs=10 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=1000 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=38" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=3 --cs=10 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=39" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=5 --cs=10 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=40" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=5 --cs=10 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=1000 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=41" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=5 --cs=10 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=42" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=5 --cs=10 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=1000 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=43" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=5 --cs=10 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=44" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=5 --cs=10 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=1000 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=45" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=5 --cs=10 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=46" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=5 --cs=10 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=1000 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=47" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=3 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=10 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=48" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=3 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=10 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=49" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=3 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=10 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=50" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=3 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=10 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=51" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=3 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=10 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=52" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=3 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=10 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=53" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=3 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=10 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=54" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=3 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=10 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=55" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=5 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=10 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=56" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=5 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=10 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=57" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=5 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=10 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=58" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=5 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=10 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=59" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=5 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=10 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=60" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=5 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=10 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=61" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=5 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=10 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=62" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=5 --cs=1000 --nCapacity=5 --mtbf=300 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=10 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=63" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=3 --cs=10 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=1000 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=64" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=3 --cs=10 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=65" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=3 --cs=10 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=1000 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=66" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=3 --cs=10 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=67" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=3 --cs=10 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=1000 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=68" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=3 --cs=10 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=69" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=3 --cs=10 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=1000 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=70" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=3 --cs=10 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=71" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=5 --cs=10 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=72" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=5 --cs=10 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=1000 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=73" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=5 --cs=10 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=74" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=5 --cs=10 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=1000 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=75" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=5 --cs=10 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=76" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=5 --cs=10 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=1000 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=77" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=5 --cs=10 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=78" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=5 --cs=10 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=1000 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=79" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=3 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=10 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=80" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=3 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=10 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=81" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=3 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=10 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=82" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=3 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=10 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=83" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=3 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=10 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=84" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=3 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=10 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=85" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=3 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=10 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=86" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=3 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=10 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=87" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=5 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=10 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=88" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=5 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=10 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=89" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=5 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=10 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=90" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=5 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=10 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=91" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=5 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=10 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=92" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=5 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=10 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=93" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=5 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=10 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=94" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=5 --cs=1000 --nCapacity=2 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=10 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=95" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=3 --cs=10 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=10 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=96" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=3 --cs=10 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=10 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=97" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=3 --cs=10 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=10 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=98" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=3 --cs=10 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=10 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=99" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=3 --cs=10 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=10 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=100" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=3 --cs=10 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=10 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=101" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=3 --cs=10 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=10 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=102" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=3 --cs=10 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=10 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=103" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=5 --cs=10 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=10 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=104" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=5 --cs=10 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=10 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=105" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=5 --cs=10 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=10 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=106" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=5 --cs=10 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=10 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=107" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=5 --cs=10 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=10 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=108" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=5 --cs=10 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=10 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=109" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=5 --cs=10 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=10 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=110" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=5 --cs=10 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=10 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=111" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=3 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=112" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=3 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=1 --speed=1000 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=113" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=3 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=uniform --runNumber=114" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=3 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=1 --speed=1000 --delay=10 --policy=Lru --consumerRequests=exponential --runNumber=115" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=3 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=116" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=3 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=1 --speed=1000 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=117" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=3 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=uniform --runNumber=118" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=3 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=1 --speed=1000 --delay=1 --policy=Lru --consumerRequests=exponential --runNumber=119" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=5 --replication=5 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=1000 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=120" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=5 --replication=5 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=5 --nbFailure=4 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=121" &
sleep 120
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=5 --replication=5 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=1000 --delay=10 --policy=Lru --consumerRequests=uniform --runNumber=122" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=5 --replication=5 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=5 --nbFailure=4 --speed=1000 --delay=1 --policy=Fifo --consumerRequests=exponential --runNumber=123" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=20 --segments=10 --replication=5 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=1000 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=124" &
sleep 30
./waf --run="data-scenario --dimension=10 --nbStorages=20 --segments=10 --replication=5 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=1 --nbUser=10 --nbFailure=4 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=125" &
sleep 30
./waf --run="data-scenario --dimension=8 --nbStorages=40 --segments=10 --replication=5 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=30 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=1000 --delay=1 --policy=Lru --consumerRequests=uniform --runNumber=126" &
sleep 120
./waf --run="data-scenario --dimension=10 --nbStorages=40 --segments=10 --replication=5 --cs=1000 --nCapacity=5 --mtbf=700 --mfd=100 --nbAdmin=3 --nbUser=10 --nbFailure=4 --speed=1000 --delay=10 --policy=Fifo --consumerRequests=exponential --runNumber=127" &
sleep 120
