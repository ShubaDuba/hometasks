let input = [1; 3; 7; 13]

let listCirc list = 
    let rec circ list acc =
        match list with
        |(h::t) -> circ t (h::acc)
        |[] -> acc
    circ list []

let output = listCirc input
printfn "Circulated List :%A" output