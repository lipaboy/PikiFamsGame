namespace PikiFamsEntryPoint

open PikiFams.PikiFamsGame

module Main =

    type MyClass(stop: int, start: int) =
        let mutable prop = 1
        let mutable _key = 5

        //extra code to be done at construction time
        do printfn "the stop equals %i" stop

        member mem.setKey (x:int) = 
            _key <- x    
        member me.Stop = stop
        member me.Start = start

        member this.MyProp 
            with get() = prop 
            and set(value) =  prop <- value
        member val ReadWriteAuto = 0 with get, set

    [<EntryPoint>]
    let main argv = 

        let myClass = new MyClass(3, 4)
        myClass.setKey 228
        myClass.MyProp <- 5
        printfn "%i" myClass.MyProp
        myClass.ReadWriteAuto <- 7
        printfn "%i" myClass.ReadWriteAuto

        let game = new GameCreator()
        let info = game.Guess [|1 .. 4|]
        printfn "Info: %d pikis, %d famas" info.Pikis info.Famas

        0 // return an integer exit code
