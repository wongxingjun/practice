/*Just a simple test on Spark*/
import org.apache.spark.SparkContext
import org.apache.spark.SparkContext._
import org.apache.spark.SparkConf

object simpleTest{
	def main(args: Array[String]){
		val file = "hdfs://server5:9000/tmp/input.txt"  //Read data from HDFS
		val conf = new SparkConf().setAppName("Simple Test")
		val sc = new SparkContext(conf)
		val data = sc.textFile(file, 2).cache()
		val num = data.filter(line => line.contains("wangxingjun")).count()
	    println("Line contains wangxingjun is : %s".format(num))
	}
}

