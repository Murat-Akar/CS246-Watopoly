export module subject;
import observer; 

export class Subject {
protected:
    std::vector<Observer*> observers;

public:
    void attach(Observer* o);
    void detach(Observer* o);
    void notifyObservers() const;

    virtual ~Subject() = default;
};