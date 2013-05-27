#include <iostream>
#include <vector>

class Name_value
{
    public:
        std::string name;
        int score;
        Name_value(std::string in_name,int in_score);


};

Name_value::Name_value(std::string in_name, int in_score)
    :name(in_name), score(in_score)
{
}

void insert_name_scores(std::vector<Name_value>& name_scores, Name_value name_score)
{
    name_scores.push_back(name_score);
}
int main()
{
    std::vector<Name_value> name_scores;
    return 0;
}
