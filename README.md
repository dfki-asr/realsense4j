# realsense4j
realsense4j provides a JNI wrapper for Intel®'s consumer grade 3D Realsense™ cameras.

$ mvn clean install -P MacOSX
$ java -Djava.library.path="../../native/MacOSX/target" -cp realsense4j-java-0.0.1-SNAPSHOT.jar de.dfki.resc28.realsense4j.BasicTest


```
git clone https://github.com/rmrschub/realsense4j.git
cd realsense4j 
git clone https://github.com/IntelRealSense/librealsense.git src/main/c++/librealsense
```