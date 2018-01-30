namespace PikiFams

open System

module PikiFamsGame =
    let digits = [0 .. 9]

    let CORTEGE_LEN = 4;
    type GameCortege = Array
    
    let getRandItem list =
        let rand = new Random()
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
    
    let getRandCortege =
        Seq.toArray (Seq.take CORTEGE_LEN (randCortege digits))

    //type GameCreator

