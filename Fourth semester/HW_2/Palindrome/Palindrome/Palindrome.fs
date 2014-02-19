let str = "avavava"

let palindrome (str:string) =
    let reverse (x:string)=
        let rec foo str=
            match str with
            |"" -> ""
            |tmp -> foo tmp.[1..] + tmp.[0..0]
        foo x
    match str.Equals(reverse str) with
    |true -> printfn "String is palindrome!"
    |false -> printfn "String is not palindrome!"

palindrome str
