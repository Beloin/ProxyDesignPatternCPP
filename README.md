# Proxy Pattern

Do your objects get too long to load?
Do you need a cache proxy to your items?

CachedItem!
 - Item that need to be fetched/created
 - Timestamp for item creation.

HttpRequest interface.

Item: Slow fetched item implements HttpRequest

ItemProxy implements HttpRequest
 - CachedItems
 - Clear timestamp (when to clear)

