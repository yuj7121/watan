#include "student.h"

//ctor
Student::Student(Colour colour) : colour{colour} {
  switch(colour) {
    case Colour::BLUE:
      index = 0;
      break;
    case Colour::RED:
      index = 1;
      break;
    case Colour::ORANGE:
      index = 2;
      break;
    case Colour::YELLOW:
      index = 3;
      break;
  }
}

//getter functions
int Student::getIndex() const { return index; }
Colour Student::getColour() const { return colour; }
int Student::getResource(ResourceType type) const {
  return resources.count(type) ? resources.at(type) : 0;
}
std::vector<std::shared_ptr<Goal>> Student::getGoals() const { return goals; }
std::vector<std::shared_ptr<Criteria>> Student::getCriterion() const { return criterion; }

bool Student::hasResources(std::vector<ResourceType> types) const {
  for (ResourceType t : types) {
      if (getResource(t) <= 0) return false;
  }
  return true;
}

//other functions
void Student::addResource(ResourceType type) {
  if (resources.count(type) == 0) {
    resources.insert({type, 1});
  } else {
    resources.at(type) = resources.at(type) + 1;
  }
}

void Student::removeResource(ResourceType type) {
  resources.at(type) = resources.at(type) - 1;
}


void Student::playGoal(shared_ptr<Goal> goal) {
  if(goal->playGoal(this)){
    goals.emplace_back(goal);
  }
}

void Student::playCriteria(shared_ptr<Criteria> criteria, bool startOfGame) {
  //if they succeed in buying/updating the criteria
  if(criteria->playCriteria(this, startOfGame)) {
    int index = criteria->getIndex();
    bool alreadyExists = false;
    //checks if the criteria already exists or not and adds to vector if needed
    for(auto it = criterion.begin(); it != criterion.end();){
      if((*it)->getIndex() == index) {
        alreadyExists = true;
        break;
      }
    }
    if(!alreadyExists) {
      criterion.emplace_back(criteria);
    }
  }
}

int Student::calculatePoints() const { 
  int point = 0; 
  for (auto &it : criterion) { 
    point += criterion->getLevel();
  }

  return point; 
}

string Student::status() const {
  string output; 
  ostringstream oss; 
  oss << calculatePoints(); 
  output = colour + " has " + oss.str() + " victory points, "; 
  for (int i = 0; i < 5; ++i) {
    ostringstream val;
    if (i == 0) {
      val << resource.at(ResourceType::CAFFEINE); 
      output += val.str(); 
      output += " caffeines, ";
    } else if (i == 1) {
      val << resource.at(ResourceType::LAB); 
      output += val.str(); 
      output += " labs, ";
    } else if (i == 2) {
      val << resource.at(ResourceType::LECTURE); 
      output += val.str(); 
      output += " lectures, ";
    } else if (i == 3) {
      val << resource.at(ResourceType::TUTORIAL); 
      output += val.str(); 
      output += " tutorials, ";
    } else if (i == 4) {
      val << resource.at(ResourceType::STUDY); 
      output += val.str(); 
      output += " studies.";
    } 
  }
  return output; 
}

string Student::criteria() const {
	string output; 
  output = colour + " has completed: "; 
  for (auto c : criterion) {
    ostringstream oss; 
    oss << c->getIndex() << " "; 
    oss << c->getCompletionLevel();
    output += oss.str() + "\n";
  }
  return output; 
}

string Student::save() const {
    string output;

    for (int i = 0; i < 5; ++i) {
        ostringstream val;
        val << resources[i];
        output += val.str() + " ";
    }

    output += "g ";
    for (auto &g : goals) {
        ostringstream goal;
        goal << g;
        output += " " + goal.str() + " ";
    }

    output += "c ";
    for (auto &c : criterion) {
        ostringstream criteria;
        ostringstream level;
        criteria << c.first;
        level << c.second;
        output += " " + criteria.str() + " " + level.str();
    }
    return output;
}

string Student::steal(Student *from) {

}