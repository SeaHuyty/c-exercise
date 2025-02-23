        // Validate seat number
        if (seatNum < 1 || seatNum > seats) {
          printf("Seat number %d is invalid. \t\t\tPlease choose a seat number between 1 and %d.\n", seatNum, seats);
          i--;
          continue;
        }

        int isReserved = 0;
        // Check for reserved seats only (not empty ones)
        for (int j = 0; j < seats; j++) {
          if (seatArray[j] == seatNum && seatArray[j] != 0) {
            isReserved = 1;
            break;
          }
        }
        for (int k = 0; k < i; k++) {
          if (unavailable[k] == seatNum) {
            isReserved = 1;
            break;
          }
        }
        if (isReserved) {
          printf("Seat %d is available.\n", seatNum); // Added message for available seat
          continue;
        } else {
          printf("Seat %d is not available.\n", seatNum);
          unavailable[i] = seatNum;
        }