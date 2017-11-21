#include <aubio.h>

int main (void)
{
  uint_t win_s = 512; // fft size
  uint_t n_filters = 40; // number of filters
  uint_t n_coefs = 13; // number of coefficients
  smpl_t samplerate = 16000.; // samplerate
  cvec_t *in = new_cvec (win_s); // input buffer
  fvec_t *out = new_fvec (n_coefs); // output coefficients
  float *result;
  float input[win_s];
  // create mfcc object
  //aubio_mfcc_t *o = new_aubio_mfcc (win_s, n_filters, n_coefs, samplerate);
  args_init(win_s,n_filters,n_coefs,samplerate);
  cvec_norm_set_all (in, 1.);
  //aubio_mfcc_do (o, in, out);
  //fvec_print (out);
  uint_t j = 0;
  /*
  for(j=0;j<win_s;j++)
  {
      input[j] = in->norm[j];
  }
  */
  memcpy(input,in->norm,sizeof(float) * win_s);
  result = mfcc_compute(input);
  for(j=0;j<39;j++)
  {
      printf("%f ",result[j]);
  }
  printf("\n");
  cvec_norm_set_all (in, .5);
  clean_mf();
//  aubio_mfcc_do (o, in, out);
//  fvec_print (out);

  // clean up
//  del_aubio_mfcc (o);
//  del_cvec (in);
//  del_fvec (out);
//  aubio_cleanup ();

  return 0;
}
