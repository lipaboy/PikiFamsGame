namespace PikiFams

open System

// PLAN
//------
// TODO: connect the tests
//-----
// READ
//-----
// READ: about inheritance
// READ: about namespaces and scopes
// READ: about inner fields

module PikiFamsGame =
    open System.Security.Cryptography.X509Certificates
    open System.Globalization

    let digits = [0 .. 9]

    let CORTEGE_LEN = 4;
    type GameCortege = Array
    
    let rand = new Random()

    let getRandItem list =
        let len = List.length list
        list |> List.item (rand.Next() % len)
    
    let randCortege list = 
        let rec loop list =
            seq { 
                let item = getRandItem list
                yield item
                yield! (List.except [item] list |> loop)
                }
        loop list
    
    let getRandCortege() =
        Seq.toArray (Seq.take CORTEGE_LEN (randCortege digits))

    //---------------GameCreator-------------//

    type GameTurnInfo(pikis : int, famas : int) =
        member this.Pikis = pikis
        member this.Famas = famas

    type GameCreator(guessingNumber:GameCortege) =
        let guessingNumber = guessingNumber
        let mutable turnCount_ = 0
        
        let makeTurn() = turnCount_ <- turnCount_ + 1
        member this.TurnCount() = turnCount_
        //TODO: throw exception if length is not appropriate
        
        new() =
            let cort = getRandCortege()
            cort |> Array.iter (printf "%d ")
            printfn ""
            GameCreator(cort)

        member this.Guess(likelyNumber:GameCortege) =
            makeTurn()
            let mutable pikis = 0
            let mutable famas = 0
            for i in 0 .. guessingNumber.Length - 1 do
                for j in 0 .. likelyNumber.Length - 1 do
                    if (likelyNumber.GetValue(j) = guessingNumber.GetValue(i)) then
                        if (i = j) then
                            pikis <- pikis + 1
                        else
                            famas <- famas + 1
            new GameTurnInfo(pikis, famas)

    //----------Tests-------------//

    let testGuess() =
        let game = new GameCreator([|1; 2; 3; 4|])
        let info = game.Guess([|2; 1; 3; 0|])
        assert(info.Famas = 2)
        assert(info.Pikis = 1)

    let runAllTheTests =
        testGuess()

            


    //type GameCreator

