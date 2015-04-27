package main

import (
    "fmt"
    "time"
)

func typeprint(s string) {
    for _, j := range s {
        if string(j) == "\n" {
            fmt.Printf("\n")
        } else {
            fmt.Printf("%c", j)
        }

        time.Sleep(time.Millisecond * time.Duration(10))
    }
}
