package main

import (
    "os"
    "io/ioutil"
    "fmt"
    "time"
)

func processFile(filename string) {
    file, err := ioutil.ReadFile(filename)

    if err != nil {
        panic(err)
    }

    for _, j := range file {
        if string(j) == "\n" {
            fmt.Printf("\n")
        } else {
            fmt.Printf("%c", j)
        }

        time.Sleep(time.Millisecond * time.Duration(10))
    }
}

func main() {
    args := os.Args[1:]

    if len(args) == 1 {
        processFile(args[0])
    } else {
        fmt.Println("needs a file to process")
    }
}
