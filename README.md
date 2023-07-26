## LearnCNNL  

### Dependencies  

* Hardware:  
Cambrian MLU 270
* Software:  
cncc v2.15.2  
cnrt 4.10.1  
cnnl 1.30

### Examples:  
#### Run ``MultiAdd``:  
1. Initialization environment:  
    ```shell
    chmod +x ./env.sh
    . ./env.sh
    ```  

2. Compile MultiAdd and Run:  
    ```shell
    cd ./MultiAdd
    mkdir build
    cd build
    cmake ..
    make
    ./MultiAdd
    ```   



