#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

struct Interval {
  int start, end, message;
  Interval() {}
  Interval(int s, int e, int m) { message = m; end = e; start = s; }
  void print() const { cout << message << ' ' << start << ' ' << end; }
};

struct compare {
  bool operator() (Interval const &first, Interval const &second) {
    return first.start > second.start;
  }
};

int t, nm, np, sizes[6], order[6], a, b, c, last_packet[6];
Interval packets[1005];
priority_queue<Interval, vector<Interval>, compare> buckets[6];

int getBuffer() {
  for (int i = 0; i < nm; i++) buckets[i] = priority_queue<Interval, vector<Interval>, compare>(), last_packet[i] = 0;
  int current_idx = 0, buffer_size = 0, largest_buffer = 0;

  for (int i = 0; i < np; i++) {
    // Can we pass this packet through?
    if (order[current_idx] == packets[i].message and last_packet[order[current_idx]] + 1 == packets[i].start) {
      last_packet[order[current_idx]] = packets[i].end;

      if (last_packet[order[current_idx]] == sizes[order[current_idx]]) current_idx++;

      // Remove any remaining packets in the bucket for this message
      while (buckets[order[current_idx]].size() > 0 and buckets[order[current_idx]].top().start == last_packet[order[current_idx]] + 1) {
        last_packet[order[current_idx]] = buckets[order[current_idx]].top().end;
        buffer_size -= buckets[order[current_idx]].top().end - buckets[order[current_idx]].top().start + 1;
        buckets[order[current_idx]].pop();

        if (last_packet[order[current_idx]] == sizes[order[current_idx]]) current_idx++;
      }
    } else {
      // Can't pass through, must add to buffer
      buckets[packets[i].message].push(packets[i]);
      buffer_size += packets[i].end - packets[i].start + 1;
      largest_buffer = max(largest_buffer, buffer_size);
    }
  }

  return largest_buffer;
}


int main() {
  while (cin >> nm >> np and np != 0 and np != 0) { t++;
    for (int i = 0; i < nm; i++) order[i] = i;
    for (int i = 0; i < nm; i++) cin >> sizes[i];
    for (int i = 0; i < np; i++) { cin >> a >> b >> c; packets[i].message = a - 1; packets[i].start = b; packets[i].end = c; }
    int buffer = INT_MAX;

    do {
      buffer = min(getBuffer(), buffer);
    } while (next_permutation(order, order + nm));
    cout << "Case " << t << ": " << buffer << endl << endl;
  }
  return 0;
}
