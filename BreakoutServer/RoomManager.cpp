#include "pch.h"
#include "RoomManager.h"

#include "Protocol.pb.h"
#include "ServerPacketHandler.h"

RoomManager GRoomManager;

//락 안잡아서 문제 생길 수 있음
int RoomManager::AddPlayer(GameSessionRef session)
{
	WRITE_LOCK;
	for(int i = 0; i<99;i++)
	{
		if(_rooms[i]->isPlay())
			continue;
		if (_rooms[i]->isFull() == false)
		{
			_rooms[i]->AddSession(session);
			return i;
		}
	}
	return -1;
}

bool RoomManager::RemovePlayer(GameSessionRef session,int roomNumber)
{
	//return _rooms[roomNumber]->RemoveSession(session);
	return true;
}

void RoomManager::Loop()
{
	P_Event()
	for (int i = 0; i < 99; i++)
	{
		if(_rooms[i]->isFull() == false)
			continue;

		switch (_rooms[i]->GetState())
		{
		case Room::MATCHING:
			cout << "room Ready" << endl;
			_rooms[i]->WaitPlayer();
			break;
		case Room::READY:
			if (_rooms[i]->isReady())
			{
				_rooms[i]->PlayStart();
			}
			break;
		case Room::START:
			_rooms[i]->Broadcast();
			break;
		default:
			break;
		}
	}

	
}
