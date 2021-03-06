CREATE TABLE available_flights(
    num_flight int,
    flights_date date,
    available_seats int,
    price float
);

CREATE TABLE bookings(
    num_flight int,
    booking_date date,
    passenger int,
    price float
);