## OpenGL Dojo ##

[![Linux](https://github.com/zpervan/OpenGlDojo/actions/workflows/ubuntu_ci.yml/badge.svg)](https://github.com/zpervan/OpenGlDojo/actions/workflows/ubuntu_ci.yml)

This repository is a testing and playground for OpenGL. Currently, it only works Ubuntu 20.04.3 but will 
be enabled on Windows also in some point of time.

Libraries related to OpenGL and located in the `ThirdParty` folder are build from scratch for the Ubuntu version 
mentioned above, so it could happen that the application won't work on other Linux distributions.

### Installation ###

Open your terminal and run the `install_ubuntu.sh` script with `sudo` privileges.
Execute the following commands at the root of the repository.
```bash
~/OpenGlDojo $ sudo chmod +X ./Scripts/install_ubuntu.sh
~/OpenGlDojo $ sudo ./Scripts/install_ubuntu.sh
```

### Additional ###

This repository is following "[Learn OpenGL](https://learnopengl.com/)" examples and instructions.