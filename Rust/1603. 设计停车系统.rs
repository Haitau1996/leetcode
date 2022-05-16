// Rust OO 太抽象了

struct ParkingSystem {
    capacity: Vec<i32>,
}
/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl ParkingSystem {
    fn new(big: i32, medium: i32, small: i32) -> Self {
        Self {
            capacity: vec![0, big, medium, small],
        }
    }

    fn add_car(&mut self, car_type: i32) -> bool {
        self.capacity[car_type as usize] = self.capacity[car_type as usize] - 1;
        self.capacity[car_type as usize] >= 0
    }
}
