# ConsumerProducer

Consumer/producer-type app. 

The two entities run on separate threads. Producer will be awaken by the consumer using a condition variable, when new data has entered the queue. Queue access(push/pop)
is limited by using a mutex. The producer will generate random numbers between 1 and 10 using the Merssene twister, at 1 second intervals. 


#install

-make all
-make clean - delete binaries and obj files.
