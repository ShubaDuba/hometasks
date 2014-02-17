open System;

let n = Int32.Parse(Console.ReadLine())

let rec fib i =        
  match i with        
  | 1 | 2 -> 1        
  | i -> fib(i-1) + fib(i-2)

printfn "%i" (fib n)