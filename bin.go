package main

import (
    "os"
    "io/ioutil"
    "fmt"
)

func processFile(filename string) {
    file, err := ioutil.ReadFile(filename)

    if err != nil {
        panic(err)
    }

    typeprint(string(file))
}

func main() {
    args := os.Args[1:]

    if len(args) == 1 {
        processFile(args[0])
    } else {
        fmt.Println("needs a file to process")
    }
}
