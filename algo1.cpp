#include <iostream>
#include <vector>

class QuickUnion{
private: 
  std::vector<int> Id;

public:
  QuickUnion(std::vector<int> Index): Id{Index} {}
  ~QuickUnion();

  int root(int i);
  bool connected(int p, int q);
  void Union(int p, int q);
 
};

int QuickUnion::root(int i)
{
  while (i !=Id[i])
    {
      i = Id[i];
    }  
  return i;
}

bool QuickUnion::connected(int p, int q)
{
  return root(p)==root(q);
}

void QuickUnion::Union(int p, int q)
{
  int i = root(p);
  int j = root(q);
  Id[i] = j;
}
//////////////////

class QuickFind{
private:
  std::vector<int> Id;
  int N;

public:
  QuickFind(int n): Id{}, N{n} {
    for(auto i =0; i< N; i++)
      Id.push_back(i);
  }
  //~QuickFind();
  
  bool connected(int p, int q);
  void Union(int p, int q);
  void Print();
};

bool QuickFind::connected(int p, int q)
{
  return Id[p]==Id[q];
}

void QuickFind::Union(int p, int q)
{
  int pid = Id[p];
  int qid = Id[q];
  for (auto i=0; i<Id.size();i++ )
    if (Id[i]==pid) Id[i] = qid;
}

void QuickFind::Print()
{
  std::string temp = "";
  
  for(auto i=0; i < Id.size(); i++)
    {
      temp = temp + std::to_string(Id[i]);
      temp = temp+" ";
    }

  std::cout << temp << std::endl;
}

int main()
{
  
  const int N = 10;
  
  QuickFind qf(N);
  qf.Union(0,9);
  qf.Union(3,6);
  qf.Union(2,7);
  qf.Union(4,9);
  qf.Union(3,7);
  qf.Union(9,1);

  qf.Print();
  
  return 0;
}
