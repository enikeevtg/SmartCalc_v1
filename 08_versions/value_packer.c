int value_packer_v1(char** str, node_t* pcontainer) {
  pcontainer->token_type = NUMBER;
  sscanf(*str, "%lf", &(pcontainer->token_value));
  const char numbers_chars[] = "1234567890";
  *str += strspn(*str, numbers_chars);
  if (**str == '.') {
    *str += 1;
    *str += strspn(*str, numbers_chars);
  }
  return OK;
}
