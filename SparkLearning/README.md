This example is just a silly copy from http://spark.apache.org/docs/latest/quick-start.html.

To run this example, you should confirm:

1)Java(1.6 or higher)

2)scala(2.9.3 or higher)

3)spark(1.0.0 or you should change the sbt file)

4)HDFS(2.2.0 which matches spark-1.0.0 or other versions with a proper spark version)

Then layout the files as follows:

simpleTest/

simpleTest/test.sbt

simpleTest/src/main/scala/simpleTest.scala


After all editing and setting, let's generate the package

$sbt package

Finally,let's run the app

cd YOUR_SPARK_HOME

./bin/spark_submmit \

--class "simpleTest" \

--master local[2] \

target/scala-2.9.3/(YOUR_jar_Name)
