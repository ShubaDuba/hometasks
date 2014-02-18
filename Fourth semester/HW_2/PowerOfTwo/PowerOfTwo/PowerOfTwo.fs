let input = 4.

let listPowersOfTwo first =
    let last = first + 4.
    [for x in first..last -> 2. ** x]
    

let output = listPowersOfTwo input
printfn "Powers Of Two List :%A" output

