open System;

let n = Int32.Parse(Console.ReadLine())

let rec fact i =        
  match i with        
  | 1 -> 1        
  | i -> i * fact(i-1)

printfn "%i" (fact n)
