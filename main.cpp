#include "mine.h"

int main(int argc, char **argv) {
	unsigned int n, m, mineCount;
	cout<<"请输入网络大小和地雷数量.示例: 10 11 12 表示 10*11的网格中包含有12个地雷，为了降低计算量，设定地雷数不能少于总数的10%"<<endl;
	for(;;) {
		cin>>n>>m>>mineCount;
		if (n > N || m > M || n <= 0 || m<= 0 || m * n / 10.0 > mineCount || mineCount > m * n) {
			cerr<<"游戏数据设定有误，考虑重新设定数值,确保地雷数量是占10%以上"<<endl;
			continue;
		} else {
			break;
		}
	}
	Mine *mine = new Mine(n, m, mineCount);
	int cmd, x, y;
	for(;;) {
		cout<<"游戏当前状态:"<<endl;
		mine->ShowMap();
		cout<<"请输入操作码和操作，操作码： 1、标记地雷 2、打开格子"<<endl;
		cin>>cmd>>x>>y;
		if (mine->IsOutOfBound(x, y)) {
			continue;
		}
		if (cmd == CMD_MARK_MINE) {
			mine->SetMine(x, y);
			if (mine->IsWin()) {
				cout<<"恭喜获胜，游戏结束"<<endl;
				break;
			}
		} else if (cmd == CMD_OPEN) {
			if (mine->IsMark(x, y)) {
				continue;
			} else if (mine->IsMine(x, y)) {
				cout<<"啪啪啪，GameOver"<<endl;
				break;
			}
			mine->CalculateValues(x, y);
		} else {
			continue;
		}
	}
}
