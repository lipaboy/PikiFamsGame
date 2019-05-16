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

    // return random element from list
    let getRandItem list =
        let rand = new Random()
        let len = List.length list
        list |> List.item (rand.Next() % len)
    
    // shuffle collection and save it to sequance
    let randCortege list = 
        let rec loop list =
            seq { 
                let item = getRandItem list
                // push elem to seq
                yield item
                // Hook the next element by recursion 
                // after removing the pushed elem from input list.
                // The new list without elem is translated to loop as parameter.
                yield! (List.except [item] list |> loop)
                }
        loop list
    
    let getRandCortege() =
        Seq.toArray (Seq.take CORTEGE_LEN (randCortege digits))

    //---------------GameCreator-------------//

    // Structure Turn Info
    type GameTurnInfo(pikis : int, famas : int) =
        member this.Pikis = pikis
        member this.Famas = famas

    type GameCreator(guessingNumber : GameCortege) =
        let guessingNumber = guessingNumber
        let mutable turnCount_ = 0
        
        let makeTurn() = turnCount_ <- turnCount_ + 1
        member this.TurnCount() = turnCount_
        //TODO: throw exception if length is not appropriate
        
        // construction without paramteres
        new() =
            let cort = getRandCortege()
            // Debug for
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

