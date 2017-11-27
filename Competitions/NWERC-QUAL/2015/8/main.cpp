#include <iostream>

void solve() {
	int counter = 1;
	while(true) {
		char c = getchar();
		if(c == '\n') {
			counter++;
			continue;
		}

		if(c == 'Z') {
			while((c = getchar()) != ' ') {
				if(c == '\n') counter++;
			}

			int digit = 0;
			while(true) {
				c = getchar();
				if(c == '\n') {counter++; continue;}
				if(c == ';') break;
				if(c == 'E') {

					while((c = getchar()) != 'E') {
						if(c == '\n') ++counter;
					}
					return;

				}
				digit *= 10;
				digit += c - '0';
			}

			std::cout << counter << ": " << "Zombies: " << digit << ";" << std::endl;
			continue;
		}

		if(c == 'R') {
			while((c = getchar()) != ';') {
				if(c == '\n') counter++;
				if(c == 'E') {
					while((c = getchar()) != 'E') {
						if(c == '\n') ++counter;
					}
					return;
				}
			}

			std::cout << counter << ": " << "RUN;" << std::endl;
			continue;
		}

		if(c == 'N') {
			while((c = getchar()) != ';') {
				if(c == '\n') counter++;
				if(c == 'E') {

					while((c = getchar()) != 'E') {
						if(c == '\n') ++counter;
					}
					return;

				}
			}

			std::cout << counter << ": " << "No Zombies;" << std::endl;
			continue;
		}

		if(c == 'E') { // handle END OF CASE
			while((c = getchar()) != 'E') {
				if(c == '\n') ++counter;
			}

			return;
		}
	}
}

int main() {
	int n; std::cin >> n;

	for(int i = 0; i < n; ++i) {
		getchar();
		solve();
	}
	return 0;
}
