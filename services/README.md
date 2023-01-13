#SERVICE CONFIGURATION TUTORIAL
1. [CONFIGURE YOUR SERVICE.](#conf)
2. [INSTALL YOUR SERVICE](#install)
3. [MONITOR YOUR SERVICE](#monitor)

<a name="conf"></a>
##CONFIGURE YOUR SERVICE
1) go in PROJECT_NAME/Makefile and set variables:
   * **FOLDER_NAME**
      * with the folder name that you want to see in /usr/local/diana/current/ once built with the rest of the software
      * _in this example FOLDER_NAME=template_CPP_
   * **SERVICE_NAME**
      * with the name of the actual service (WITHOUT EXTENSION) that will be in /etc/systemd/system
      * for example if your service is anal_streamer.service, then SERVICE_NAME=anal_streamer
      * _in this example SERVICE_NAME=example_program_
   * **START_SCRIPT**
      * name of the script that launches your program
      * _in this example START_SCRIPT=start-exampleprogram.sh_
   * **STOP_SCRIPT**
      * name of the script that makes it possible to safely stop the service
      * this script may not be needed, Linux is already able to stop the service but here you have the chance to make it stop smoothly
      * _in this example STOP_SCRIPT=stop-exampleprogram.sh, but we do not use it_
   * **EXECUTABLE_NAME**
      * name of the executable (it should have the same name as the folder containing it)
      * _in this example EXECUTABLE_NAME=ExampleProgram_
2) open files PROJECT_NAME/services/start-exampleprogram.sh and stop-exampleprogram.sh and set variables:
   * **FOLDER_NAME**
      * same as in point 1
   * **EXECUTABLE_NAME**
      * name of the executable
      * _in this example EXECUTABLE_NAME=ExampleProgram_
3) open file PROJECT_NAME/services/example_program.service and modify ExecStart and ExecStop, replacing "template_CPP" with your actual FOLDER_NAME

<a name="install"></a>
##INSTALL YOUR SERVICE
After doing point 1, you can install your service with just executing the makefile rule install_service
```
$ make install_service
```
this will create the folder of your project inside /usr/local/diana/current and will initialize it with the stuff needed, you can check with this command

```
$ tree -L 4 /usr/local/diana
/usr/local/diana/current
└── template_CPP
    ├── ExampleProgram
    └── services
        ├── start.sh
        └── stop.sh
```

<a name="monitor"></a>
##MONITOR YOUR SERVICE
###See if your service MY_SERVICE.service is installed correctly
```
ls etc/systemd/system | grep MY_SERVICE.service
```
if you see your service name as output, you are good to go

###Monitor the status of your service
```
systemctl status MY_SERVICE
```

###Start your service
```
sudo systemctl start MY_SERVICE
```

###Stop your service
```
sudo systemctl stop MY_SERVICE
```

###Monitor your service output
```
journalctl -u MY_SERVICE -f
```