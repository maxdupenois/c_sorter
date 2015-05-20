#include <stdlib.h>
#include "array.h"

void merge ( int * src, int * dst,
    int seq1_start, int seq1_end,
    int seq2_start, int seq2_end, int start_index_dst);

void merge_sort (int * data, size_t size) {
  int sequence_size, last_seq, last_seq_end, seq, seq_end;
  int * buffer = calloc(size, sizeof(data[0]));
  int * tmp;
  int swapped = 0;
  int remainder, r;
  
  for(sequence_size = 1; (sequence_size < size); sequence_size = sequence_size * 2){
    last_seq = -1;
    for(seq = 0; seq < size; seq += sequence_size){
      seq_end = ((seq + (sequence_size - 1)) >= size) ? size - 1 : seq + sequence_size - 1;
      if(last_seq > -1){
        merge(data, buffer, last_seq, last_seq_end, seq, seq_end, last_seq);
        last_seq = -1;
      } else if(seq_end == (size - 1) && last_seq == -1)  {// orphaned_sequence
        for(r = seq; r <= seq_end; r++) buffer[r] = data[r];
      } else {
        last_seq = seq;
        last_seq_end = seq_end;
      }
    }

    swap_addr(&buffer, &data);
    swapped = swapped ^ 1;
  }


  // At finish, if swapped then data has the correct mapping,
  // otherwise buffer does. However if swapped buffer is the
  // one with the correct address, so copy data to buffer
  if(swapped){
    copy(data, buffer, size);
    free(data);
  }else{
    free(buffer);
  }
}

void merge ( int * src, int * dst,
    int seq1_start, int seq1_end,
    int seq2_start, int seq2_end, int start_index_dst){
  int seq1_pos, seq2_pos, dst_head;
  dst_head = start_index_dst;
  seq1_pos = seq1_start;
  seq2_pos = seq2_start;

  while(seq1_pos <= seq1_end || seq2_pos <= seq2_end){
    if (seq1_pos > seq1_end) {
      dst[dst_head++] = src[seq2_pos++];
    } else if (seq2_pos > seq2_end){
      dst[dst_head++] = src[seq1_pos++];
    } else if (src[seq1_pos] < src[seq2_pos]){
      dst[dst_head++] = src[seq1_pos++];
    } else {
      dst[dst_head++] = src[seq2_pos++];
    }
  }
}

