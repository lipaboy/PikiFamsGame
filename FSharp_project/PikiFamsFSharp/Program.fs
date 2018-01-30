namespace PikiFamsEntryPoint

open PikiFams.PikiFamsGame

module Main =

    type MyClass(stop: int, start: int) =
        member me.Stop = stop
        member me.Start = start

    [<EntryPoint>]
    let main argv = 
        getRandCortege |> Array.iter (printf "%d ")

        0 // return an integer exit code
