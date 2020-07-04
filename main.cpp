#include <vector>
#include <QTextStream>
#include <QTextCodec>
using namespace std;

QTextStream print(stdout);

void winner(vector<int> addition, int height)
{
    string str(height,'\t');
    print << endl << flush;
    vector<int> line;
    for (int j = 0; j < addition.size()-1;)
    {
        if (addition[j] > addition[j + 1])
        {
            line.push_back(addition[j]);
        }

        else line.push_back(addition[j + 1]);
        {
            j = j + 2;
        }
    }
    int j;

    if ((addition.size()%2)!=0)
    {
        line.push_back(addition[j]);
    }

    for (int i = 0; i < line.size(); i++)
    {
        print << QString::fromStdString(str) << line[i];
    }

    if (line.size() > 1)
    {
        winner(line, height + 1);
    }

    else
    {
        print << endl << QString("Выйграл ") << line[0]-1 << QString(" со счетом = ") << line[0] << flush;
    }
}

int main()
{
    print.setCodec(QTextCodec::codecForName("cp866"));

    int n = 5;
    vector<int> addition;
    for (int i = 0; i < n * 2; i++)
    {
        addition.push_back(i + 1);
    }
    print << QString("Турнирное дерево: \n") << flush;
    for (int i = 0; i < n * 2; i++)
    {
        print << QString('\t') << addition[i] << flush;
    }
    winner(addition, 2);
    print << QString("\nНажмите любую клавишу...");
    return 0;
}
