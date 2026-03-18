class Status;

class Worker {
public:
    Worker();
    ~Worker();

    void doHeavyWork(Status& status);
};
