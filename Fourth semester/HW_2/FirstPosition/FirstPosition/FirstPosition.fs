let input = [1; 4; 5; 123; 5; 123]

let firstPosition list comp =
    let flag = 0
    let rec bypass list comp flag =
        match list with
        |h :: t -> if h = comp then flag + 1 else bypass t comp (flag + 1)
        |[] -> flag * 0
    bypass list comp flag

let output = firstPosition input 123
printfn "%A" output