#include "student.h"
#include "exceptions.h"

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

void Student::setResource(ResourceType type, int count) {
  resources[type] = count;
}

void Student::addGoal(std::shared_ptr<Goal> goal) {
  goals.push_back(goal);
}

void Student::addCriterion(std::shared_ptr<Criteria> criterion) {
  this->criterion.push_back(criterion);
}

void Student::removeResource(ResourceType type) {
  resources.at(type) = resources.at(type) - 1;
}

void Student::removeResources(std::vector<ResourceType> types) {
  for (ResourceType t : types) {
    removeResource(t);
  }
}
void Student::playGoal(shared_ptr<Goal> goal) {
  if(goal->playGoal(this)){
    goals.emplace_back(goal);
    
  }

}

bool Student::playCriteria(shared_ptr<Criteria> criteria, bool startOfGame) {
  //if they succeed in buying/updating the criteria
  if(criteria->playCriteria(this, startOfGame)) {
    //int index = criteria->getIndex();
    bool dupe = false;
    for(auto it = criterion.begin(); it != criterion.end(); ++it){
      if((*it)->getIndex() == criteria->getIndex()){
        dupe = true;
      }
    }
    if(!dupe){
      criterion.emplace_back(criteria);
    }
    return true; 
  }
  return false; 
}

int Student::calculatePoints() const { 
  int point = 0; 
  for (auto &it : criterion) { 
    point += it->getCompletionLevel();
  }
  return point; 
}

string Student::status() const {
  string output; 
  std::ostringstream oss; 
  oss << calculatePoints(); 
  output = colourToString(colour) + " has " + oss.str() + " victory points, "; 
  for (int i = 0; i < 5; ++i) {
    ostringstream val;
    if (i == 0) {
      // val << resources.at(ResourceType::CAFFEINE); 
      val << getResource(ResourceType::CAFFEINE);
      output += val.str(); 
      output += " caffeines, ";
    } else if (i == 1) {
      val << getResource(ResourceType::LAB); 
      output += val.str(); 
      output += " labs, ";
    } else if (i == 2) {
      val << getResource(ResourceType::LECTURE); 
      output += val.str(); 
      output += " lectures, ";
    } else if (i == 3) {
      val << getResource(ResourceType::TUTORIAL); 
      output += val.str(); 
      output += " tutorials, ";
    } else if (i == 4) {
      val << getResource(ResourceType::STUDY); 
      output += val.str(); 
      output += " studies.";
    } 
  }
  output += "\n";
  return output; 
}

string Student::criteriaInfo() const {
	string output; 
  output = colourToString(colour) + " has completed: \n"; 
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
      if (i == 0) {
        val << getResource(ResourceType::CAFFEINE); 
        output += val.str() + " ";
      } else if (i == 1) {
        val << getResource(ResourceType::LAB); 
        output += val.str() + " ";
      } else if (i == 2) {
        val << getResource(ResourceType::LECTURE); 
        output += val.str() + " ";
      } else if (i == 3) {
        val << getResource(ResourceType::TUTORIAL); 
        output += val.str() + " ";
      } else if (i == 4) {
        val << getResource(ResourceType::STUDY); 
        output += val.str() + " ";
      } 
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
        criteria << c->getIndex();
        level << c->getCompletionLevel();
        output += " " + criteria.str() + " " + level.str();
    }
    return output;
}

void Student::trade(shared_ptr<Student> receivingStudent, const ResourceType offered, const ResourceType requested) {
    if (getResource(offered) == 0) {
        throw InsufficientResourcesException("Offering student does not have the resource to trade!");
    }
    if (receivingStudent->getResource(requested) == 0) {
        throw InsufficientResourcesException("Receiving student does not have the requested resource!");
    }
    removeResource(offered);
    addResource(requested);
    receivingStudent->removeResource(requested);
    receivingStudent->addResource(offered);
}


