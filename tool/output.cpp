#include "output.h"
#include <iostream>
#include "config/config.h"

Output g_op;

const char* PIC::GetPic()
{
	return this->pic;
}

bool PIC::SetPic(char* buf, int w, int h)
{
	if(buf == 0 || w < 1 || h < 1)
		return false;
	if (pic != 0)
	{
		free(pic);
		pic = 0;
	}

	this->w = w;
	this->h = h;
	int s = w * h;
	pic = (char*)malloc(s);
	for (int i = 0; i < s; ++i)
		pic[i] = buf[i];

	return true;
}

int PIC::GetW()
{
	return w;
}

int PIC::GetH()
{
	return h;
}

void Output::Begin()
{
	//绘制数组如果没有开辟好，不能开始使用
	if (ClientStr == 0)
		return;
	const int offset = cw * 2 + 1;
	const int size = ch * (offset);

	//末尾结束符
	ClientStr[size - 1] = '\0';

	//换行符
	for (int i = 0; i < ch - 1; i++)
	{
		ClientStr[offset * (i + 1) - 1] = '\n';
	}
	//清空其他区域
	for (int i = 0; i < ch; ++i)
	{
		for (int j = 0; j < cw; ++j)
		{
			ClientStr[offset * i + j * 2] = ' ';
			ClientStr[offset * i + j * 2 + 1] = ' ';
		}
	}

	memset(ColorStr, 0, colorfulSize);
}

void Output::DrawPic(const char* key, int x, int y, bool needTitle)
{
	if(needTitle)
		y += TITLE_HEIGHT;
	if (key == 0)
		return;
	std::map<const char*, PIC>::iterator it;
	it = PicMap.find(key);
	if (it == PicMap.end())
	{
		return;
	}
	PIC* pic = &it->second;
	const char* p = pic->GetPic();
	if (p == 0)
		return;
	int px = 0;
	int py = 0;
	int picw = pic->GetW();
	int pw = picw;
	int ph = pic->GetH();
	x = x - cx;
	y = y - cy;
	if (x < 0)
	{
		pw += x;
		px = -x;
		x = 0;
		if (pw < 0)
			return;
	}
	else if (x >= cw)
		return;
	if (x + pw > cw)
	{
		pw = pw - (pw + x - cw);
	}
	if (y < 0)
	{
		ph += y;
		py = -y;
		y = 0;
		if (ph < 0)
			return;
	}
	else if (y >= ch)
		return;
	if (y + ph > ch)
	{
		ph = ph - (ph + y - ch);
	}
	//初始相对下标 计算出来
	int pos = x + y * cw;
	int pos2 = px + py * picw;
	int s = pw * ph;
	for (int i = 0; i < s; ++i)
	{
		OutputUnitInfo& info = tsvector[p[pos2]];
		int tempIndex = pos / cw * (cw * 2 + 1) + pos % cw * 2;
		ClientStr[tempIndex] = info.getTs()[0];
		ClientStr[tempIndex + 1] = info.getTs()[1];
		pos2 += 1;
		pos += 1;
		if (i % pw == pw - 1)
		{
			y += 1;
			pos = x + y * cw;
			py += 1;
			pos2 = px + py * picw;
		}
	}
}

void Output::End()
{
	if (ClientStr == 0)
		return;
	//先清屏
	system("cls");
	int flowIndex = 0;
	for (int originIndex = 0; ClientStr[originIndex]; originIndex++)
	{
		char& temp = ClientStr[originIndex];
		if (temp == 32||temp == '\n' || temp == '_') {
			ColorStr[flowIndex] = temp;
			flowIndex++;
			continue;
		}
		std::vector<OutputUnitInfo>::iterator it = tsvector.begin();
		for (; it != tsvector.end(); it++)
		{
			OutputUnitInfo& info = *it;
			if (temp == info.getTs()[1]) {
				memcpy(&ColorStr[flowIndex], info.getTsc(), info.getLength());
				flowIndex += info.getLength();
				ColorStr[flowIndex] = ClientStr[originIndex-1];
				flowIndex++;
				ColorStr[flowIndex] = ClientStr[originIndex];
				flowIndex++;
				break;
			}
		}
	}
	std::cout << ColorStr;

	Sleep(GAME_FPS);
}

void Output::SetClientWH(int w, int h)
{
	//数据合法校验
	if (w < 1 || h < 1)
	{
		cw = 0;
		ch = 0;
	}
	cw = w;
	ch = h;
	cs = w * h;
	if (ClientStr) {
		free(ClientStr);
		ClientStr = 0;
	}
	const int offset = cw * 2 + 1;
	const int size = ch * (offset);
	ClientStr = (char*)malloc(size);

	if (ColorStr) {
		free(ColorStr);
		ColorStr = 0;
	}
	colorfulSize = size * 6;
	ColorStr = (char*)malloc(colorfulSize);
}

bool Output::AddPic(const char* key, PIC pic)
{
	if (key == 0)
		return 0;
	std::map<const char*, PIC>::iterator it;
	it = PicMap.find(key);
	if (it != PicMap.end())
		return 0;

	PicMap.insert(std::pair<const char*, PIC>(key, pic));
	return true;
}

void Output::Clear()
{
	PicMap.clear();
	tsvector.clear();
}

void Output::SetClientPos(int x, int y)
{
	cx = x;
	cy = y;
}

int Output::GetW()
{
	return cw;
}

int Output::GetH()
{
	return ch;
}

int Output::GetCX()
{
	return cx;
}

int Output::GetCY()
{
	return cy;
}

void Output::addInfo(const char* ts, const char* tsc,int length)
{
	OutputUnitInfo oui;
	oui.init(ts, tsc, length);
	this->tsvector.push_back(oui);
}

void OutputUnitInfo::init(const char* ts, const char* tsc, int length)
{
	this->ts = ts;
	this->tsc = tsc;
	this->length = length;
}

const char* OutputUnitInfo::getTs()
{
	return ts;
}

const char* OutputUnitInfo::getTsc()
{
	return tsc;
}

int OutputUnitInfo::getLength() {
	return length;
}

void Output::popBack(const char * key)
{
	PicMap.erase(key);
}
