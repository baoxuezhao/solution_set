#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int **st;


void buildUtilY(int arr[][4], int lm, int rm, int ln, int rn, int vm, int vn)
{
	if(ln == rn)
	{
		if(lm == rm)
			st[vm][vn] = arr[lm][ln];
		else
			st[vm][vn] = st[2*vm+1][vn] + st[2*vm+2][vn];
	}
	else
	{
		int midn = ln + (rn-ln)/2;
		buildUtilY(arr, lm, rm, ln, midn, vm, 2*vn+1);
		buildUtilY(arr, lm, rm, midn+1, rn, vm, 2*vn+2);
		st[vm][vn] = st[vm][2*vn+1] + st[vm][2*vn+2];
	}
} 

void buildUtilX(int arr[][4], int lm, int rm, int vm, int m, int n)
{
	if(lm != rm)
	{
		int midm = lm + (rm-lm)/2;
		buildUtilX(arr, lm, midm, 2*vm+1, m, n);
		buildUtilX(arr, midm+1, rm, 2*vm+2, m, n);
	}
	buildUtilY(arr, lm, rm, 0, n-1, vm, 0);
}


void build(int array[][4], int m, int n)
{
	int level_m = ceil(log2(m));
	int level_n = ceil(log2(n));
	int st_m = 2*(int)pow(2, level_m)-1;
	int st_n = 2*(int)pow(2, level_n)-1;
	st = new int*[st_m];
	for(int i=0; i<st_m; i++)
	{
		st[i] = new int[st_n];
	}
	buildUtilX(array, 0, m-1, 0, m, n);
}

int sumUtilY(int lm, int rm, int ln, int rn, int vm, int vn, int qln, int qrn)
{
	if(qrn < ln || qln > rn)
		return 0;
	if(ln >= qln && rn <= qrn)
	{
		return st[vm][vn];
	}
	int midn = ln + (rn-ln)/2;
	int left = sumUtilY(lm, rm, ln, midn, vm, 2*vn+1, qln, qrn);
	int right= sumUtilY(lm, rm, midn+1, rn, vm, 2*vn+2, qln, qrn);

	return left+right;
}

int sumUtilX(int lm, int rm, int vm, int qlm, int qrm, int qln, int qrn, int n)
{	
	if(qrm < lm || qlm > rm)
		return 0;
	if(lm >= qlm && rm <= qrm)
	{
		return sumUtilY(lm, rm, 0, n-1, vm, 0, qln, qrn);
	}
	int midm = lm + (rm - lm)/2;
	int left = sumUtilX(lm, midm, 2*vm+1, qlm, qrm, qln, qrn, n);
	int right= sumUtilX(midm+1, rm, 2*vm+2, qlm, qrm, qln, qrn, n);
	return left+right;
}

int sum(int qlm, int qrm, int qln, int qrn, int m, int n)
{
	return sumUtilX(0, m-1, 0, qlm, qrm, qln, qrn, n);
}


void updateUtilY(int lm, int rm, int ln, int rn, int vm, int vn, int x, int y, int value)
{
	if(ln == rn)
	{
		if(lm == rm)
			st[vm][vn] = value;
		else
			st[vm][vn] = st[2*vm+1][vn] + st[2*vm+2][vn];
	}
	else
	{
		int midn = ln + (rn-ln)/2;
		if(y <= midn)
			updateUtilY(lm, rm, ln, midn, vm, 2*vn+1, x, y, value);
		else
			updateUtilY(lm, rm, midn+1, rn, vm, 2*vn+2, x, y, value);
		st[vm][vn] = st[vm][2*vn+1] + st[vm][2*vn+2];
	}
}

void updateUtilX(int lm, int rm, int vm, int x, int y, int value, int n)
{
	if(lm != rm)
	{
		int midm = lm + (rm-lm)/2;
		if(x <= midm)
			updateUtilX(lm, midm, 2*vm+1, x, y, value, n);
		else
			updateUtilX(midm+1, rm, 2*vm+2, x, y, value, n);
	}
	updateUtilY(lm, rm, 0, n-1, vm, 0, x, y, value);
}

void update(int array[][4], int x, int y, int value, int m, int n)
{
	array[x][y] = value;
	updateUtilX(0, m-1, 0, x, y, value, n);
}

int main()
{
	int array[][4] = {{1, 2, 3, 4}, 
					  {5, 6, 7, 8},
					  {9, 10,11,12},
					  {13,14,15,16}};

	build(array, 4, 4);

	for(int i=0; i<7; i++)
	{
		for(int j=0; j<7; j++)
		{
			cout << st[i][j] << "\t";
		}
		cout << endl;
	}

	cout << sum(1, 3, 2, 3, 4, 4) << endl;

	update(array, 1, 3, 27, 4, 4);
	update(array, 3, 1, 24, 4, 4);

	cout << sum(1, 3, 2, 3, 4, 4) << endl;

	cout << sum(3, 3, 0, 3, 4, 4) << endl;

	return 0;
}
