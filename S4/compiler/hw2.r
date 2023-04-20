install.packages(c('tibble', 'dplyr', 'readr'))

library(readr)
library(dplyr)

df <- read_csv("5_School_Work\\S4\\compiler\\HW2data.csv")

print(df)

df <- df %>% mutate(Score = round(df$HW1 * 0.1 + df$HW2 * 0.1 + df$HW3 * 0.1 + df$Midterm * 0.3 + df$Final * 0.4))

print(df)

df <- df %>% mutate(Grade = case_when(Score <= 49 ~ "E",
                                Score <= 59 ~ "D",
                                Score <= 62 ~ "C-",
                                Score <= 66 ~ "C",
                                Score <= 69 ~ "C+",
                                Score <= 72 ~ "B-",
                                Score <= 76 ~ "B",
                                Score <= 79 ~ "B+",
                                Score <= 84  ~ "A-",
                                Score <= 89 ~ "A",
                                Score <= 100 ~ "A+"))
print(df)

write.csv(df,"5_School_Work\\S4\\compiler\\result_R.csv", row.names = FALSE)
