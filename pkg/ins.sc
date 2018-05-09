func install {
    cmake CMakeLists.txt
    make
    sudo mv anel /usr/bin/anel
}

func update {
    &install
}

func remove {
    sudo rm /usr/bin/anel
}