#include "output.h"
#include <iostream>

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
	//�����������û�п��ٺã����ܿ�ʼʹ��
	if (ClientStr == 0)
		return;
	const int offset = cw * 2 + 1;
	const int size = ch * (offset);

	//ĩβ������
	ClientStr[size - 1] = '\0';

	//���з�
	for (int i = 0; i < ch - 1; i++)
	{
		ClientStr[offset * (i + 1) - 1] = '\n';
	}
	//�����������
	for (int i = 0; i < ch; ++i)
	{
		for (int j = 0; j < cw; ++j)
		{
			ClientStr[offset * i + j * 2] = ' ';
			ClientStr[offset * i + j * 2 + 1] = ' ';
		}
	}
}

void Output::DrawPic(const char* key, int x, int y)
{
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
	//��ʼ����±� �������
	int pos = x + y * cw;
	int pos2 = px + py * picw;
	int s = pw * ph;
	for (int i = 0; i < s; ++i)
	{
		int tsIndex = p[pos2] * 2;
		int tempIndex = pos / cw * (cw * 2 + 1) + pos % cw * 2;
		ClientStr[tempIndex] = ts[tsIndex];
		ClientStr[tempIndex + 1] = ts[tsIndex + 1];
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
	//������
	system("cls");
	std::cout << ClientStr;
}

void Output::SetClientWH(int w, int h)
{
	//���ݺϷ�У��
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
}

void Output::SetTs(const char* ts)
{
	this->ts = ts;
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
