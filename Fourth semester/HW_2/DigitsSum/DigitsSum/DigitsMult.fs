let input = 239

let digitsMul(x:obj)=
    let rec foo str=
        match str with
        |"" -> 1
        |str -> (str.[0..0] |> int) * foo str.[1..]
    foo (x |> string)

let output = digitsMul input
printfn "%d" output
System.Console.ReadKey()