#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(string word, vector<string> pages)
{
    vector<double> base;
    vector<double> score;
    vector<vector<string>> link;
    int answer = 0;
    int size = pages.size();
    base.resize(size);
    link.resize(size);
    score.resize(size);

    for (int i = 0; i < word.size(); i++)
    {
        word[i] = tolower(word[i]);
    }
 
    for (int i = 0; i < size; i++)
    {
        int cnt = 0;

        // tolower all character.
        for (int j = 0; j < pages[i].size(); j++)
        {
            pages[i][j] = tolower(pages[i][j]);
        }

        // find the "word".
        size_t pos = 0;
        while (true)
        {
            // find next.
            pos = pages[i].find(word, pos);
            if (pos == string::npos)
                break;
            else
            {
                // check the seperated word.
                if (pages[i][pos + word.size()] > 'z' || pages[i][pos + word.size()] < 'a' || pages[i][pos + word.size()] == '\0')
                {
                    if (pages[i][pos - 1] > 'z' || pages[i][pos - 1] < 'a')
                    {
                        cnt++;
                        pos++;
                    }
                    else 
                    {
                        pos++;
                    }
                    
                }
                else
                {
                    pos++;
                }
            }
        }
        base[i] = cnt;
    }

    
    for (int i = 0; i < size; i++) {
        string target = "content=\"";
        size_t pos = 0;
        pos = pages[i].find(target, pos);
        if (pos == string::npos)
            break;
        else
        {
            // check the seperated word.
            if (pages[i][pos + target.size()] == 'h')
            {
                int a = 0;
                string str;
                while (true)
                {
                    if (pages[i][pos + target.size() + a] == '\"')
                    {
                        link[i].push_back(str);
                        break;
                    }
                    str += pages[i][pos + target.size() + a];
                    a++;
                }
            }
        }

        target = "href=\"";
        pos = 0;
        while (true)
        {
            pos = pages[i].find(target, pos);
            if (pos == string::npos)
                break;
            else
            {
                // check the seperated word.
                if (pages[i][pos + target.size()] == 'h')
                {
                    int a = 0;
                    string str;
                    while (true)
                    {
                        if (pages[i][pos + target.size() + a] == '\"')
                        {
                            link[i].push_back(str);
                            break;
                        }
                        str += pages[i][pos + target.size() + a];
                        a++;
                    }
                }
                pos++;
            }
        }
        
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < link.size(); j++) 
        {
            for (int k = 0; k < size; k++)
            {
                if (link[i][j] == link[k][0])
                {
                    score[k] += base[i] / (link[i].size() - 1);
                }
            }
        }
    }
    double maxi = 0;
    int idx = 0;
    for (int i = 0; i < size; i++)
    {
        score[i] += base[i];
        
        if (maxi < score[i])
        {
            maxi = score[i];
            idx = i;
        }
    }
    
    return idx;
}

int main()
{
    vector<string> pages =
        {"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>"};
    
    std::cout << solution("Muzi", pages);

    return 0;
}