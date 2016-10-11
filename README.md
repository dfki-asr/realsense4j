# realsense4j
realsense4j provides a JNI wrapper for Intel®'s consumer grade 3D Realsense™ cameras.

## Installation & Usage
Get and install Intel®'s [librealsense](https://github.com/IntelRealSense/librealsense).

Clone realsense4j and place into your local maven repository:
```
mvn clean compile package install -P PLATFORM_HERE
```

where `PLATFORM_HERE` specifies your target platform for art4j.

You can choose from the following options:
```
MacOSX | Linux
```

Add a dependency to your project's `pom.xml` like this
```xml
<dependency>
    <artifactId>realsense4j</artifactId>
    <groupId>de.dfki.resc28</groupId>
    <version>0.1</version>
    <type>nar</type>
</dependency>
```
and don't forget to set 
```xml
<build>
...
    <plugin>
        <groupId>com.github.maven-nar</groupId>
        <artifactId>nar-maven-plugin</artifactId>
        <version>3.5.0</version>
        <extensions>true</extensions>
        <executions>
            <execution>
                <id>unpack-nar-dependencies</id>
                <phase>package</phase>
                <goals>
                    <goal>nar-download</goal>
                    <goal>nar-unpack</goal>
                    <goal>nar-assembly</goal>
                </goals>
            </execution>
        </executions>
    </plugin>
...
</build>
```

## Contributing
Contributions are very welcome.

## License
realsense4j is subject to the license terms in the LICENSE file found in the top-level directory of this distribution. You may not use this file except in compliance with the License.

## Third-party Contents
This source distribution includes the third-party items with respective licenses as listed in the THIRD-PARTY files found in the top-level directories of this distribution's modules.

## Acknowledgements
This work has been supported by the [German Ministry for Education and Research (BMBF)](http://www.bmbf.de/en/index.html) (FZK 01IMI3001 J) as part of the [ARVIDA](http://www.arvida.de/) project.
