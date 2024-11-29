#ifndef GAMEEVENT_H
#define GAMEEVENT_H

enum GameEvent { 
    BoardInfo, // TODO: change GameEvent:: ones 
    PlayersStatus, 
    PlayerCriteria, 
    Achieve, // who: curStudent ; what: 
    Complete, 
    Improve, 
    TradeResource, // change
    Help, 
    ResourceDistribution, 
    StealResource,
    MoveGeese, 
    AnnounceWinner
};

#endif