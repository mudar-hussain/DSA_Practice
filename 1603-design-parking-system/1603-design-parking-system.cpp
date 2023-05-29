class ParkingSystem {
    int park[4] = {0};
public:
    ParkingSystem(int big, int medium, int small) {
        park[1] = big;
        park[2] = medium;
        park[3] = small;
    }
    
    bool addCar(int carType) {
        if(park[carType]){
            park[carType]--;
            return true;
        }else{
            return false;
            
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */