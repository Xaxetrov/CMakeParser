include_directories(${CMAKE_SOURCE_DIR}/dependencies/catch)

add_executable(UnitTests
  main.cpp
  ArgumentParser_tests.cpp
  ArgumentsParser_tests.cpp
  BracketArgumentParser_tests.cpp
  BracketCloseParser_tests.cpp
  BracketCommentParser_tests.cpp
  BracketContentParser_tests.cpp
  BracketOpenParser_tests.cpp
  CommandInvocationParser_tests.cpp
  EscapeEncodedParser_tests.cpp
  EscapeIdentityParser_tests.cpp
  EscapeSemiliconParser_tests.cpp
  EscapeSequenceParser_tests.cpp
  FileElementParser_tests.cpp
  FileParser_tests.cpp
  IdentifierParser_tests.cpp
  LineCommentParser_tests.cpp
  LineEndingParser_tests.cpp
  NewLineParser_tests.cpp
  QuotedArgumentParser_tests.cpp
  QuotedContinuationParser_tests.cpp
  QuotedElementParser_tests.cpp
  SeparatedArgumentsParser_tests.cpp
  SeparationParser_tests.cpp
  SpaceParser_tests.cpp
  UnquotedArgumentParser_tests.cpp
  UnquotedElementParser_tests.cpp
)
target_link_libraries(UnitTests PRIVATE CMakeParser)
