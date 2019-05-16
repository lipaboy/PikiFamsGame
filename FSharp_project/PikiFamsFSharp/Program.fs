namespace PikiFamsEntryPoint

open PikiFams.PikiFamsGame

module Main =

    [<EntryPoint>]
    let main argv = 

        let game = new GameCreator()
        let info = game.Guess [|1 .. 4|]
        printfn "Info: %d pikis, %d famas" info.Pikis info.Famas

        //runAllTheTests

        0 // return an integer exit code
