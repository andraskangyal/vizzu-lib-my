#ifndef INTERFACEJS_H
#define INTERFACEJS_H

extern "C" {
extern void openUrl(const char *);
extern void setCursor(const char *cursor);
extern void event_invoked(int, const char *);
}

#endif