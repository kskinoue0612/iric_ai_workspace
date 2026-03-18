class Status;

class Worker {
public:
    Worker();
    ~Worker();

    void doHeavyWork(Status& status);
    void openProject(Status& status);
    void saveProject(Status& status);
    void importBigData(Status& status);
    void processData(Status& status);
};
